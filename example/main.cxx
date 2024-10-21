#include <print>
#include <rqt>

class MyObject : public QObject {
    R_OBJECT

    R_PROPERTY(int, testProp, R_READ(getTestProp), R_WRITE(setTestProp), R_NOTIFY(chgTestProp))

   public:
    R_SLOT int getTestProp() const {
        std::println("get -> {}", m_testProp);
        return m_testProp;
    }

    R_SLOT void setTestProp(int value) {
        std::println("set({})", value);
        if (m_testProp != value) {
            m_testProp = value;
            chgTestProp(value);
        }
    }

    R_SIGNAL void chgTestProp(int value) {
        R_SIGNAL_IMPL(MyObject, chgTestProp, value);
    }

    R_INVOKABLE int testInvokable(int x, int y) {
        std::println("invoke({}, {}) -> {}", x, y, x * y);
        return x * y;
    }

   private:
    int m_testProp;
};

R_OBJECT_IMPL(MyObject)

int main() {
    MyObject obj;
    std::println("{}", obj.metaObject()->className());
    QMetaObject::invokeMethod(&obj, "testInvokable", Q_ARG(int, 123), Q_ARG(int, 456));
    QObject::connect(&obj, &MyObject::chgTestProp, [&](auto value) { std::println("chg({})", obj.getTestProp()); });
    QMetaObject::invokeMethod(&obj, "setTestProp", Q_ARG(int, 1337));
    return 0;
}
