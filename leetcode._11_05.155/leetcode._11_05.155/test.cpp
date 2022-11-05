class MinStack {
public:
    //�Զ������͵����캯��������
    MinStack() {

    }
    //Ϊ�ջ��ߵ���С��
    void push(int val) {
        _st.push(val);
        if (_min.empty() || _min.top() >= _st.top())
        {
            _min.push(val);
        }
    }

    void pop() {
        if (_min.top() == _st.top())
        {
            _min.pop();
        }
        _st.pop();
    }

    int top() {
        return _st.top();
    }

    int getMin() {
        return _min.top();
    }

    stack<int> _st;
    stack<int> _min;
};