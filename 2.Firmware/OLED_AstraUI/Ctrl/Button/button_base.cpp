#include "button_base.h"

void ButtonBase::Tick(uint32_t _timeElapseMillis)
{
    timer += _timeElapseMillis;
    bool pinIO = ReadButtonPinIO(id);

    if (lastPinIO != pinIO)
    {
        if (pinIO)  // 按钮被释放
        {
            OnEventFunc(UP);

            if (isSingleClickPending)  // 如果已经记录了一个单击等待双击
            {
                if (timer - lastReleaseTime <= doubleClickTime)  // 判断双击
                {
                    OnEventFunc(DOUBLE_CLICK);
                    isSingleClickPending = false;  // 双击触发，清除等待
                }
            }
            else  // 不是等待双击的状态
            {
                if (timer - pressTime > longPressTime)
                {
                    OnEventFunc(LONG_PRESS);
                }
                else
                {
                    isSingleClickPending = true;    // 标记等待单击事件是否转为双击
                    lastReleaseTime = timer;       // 记录这次释放时间
                }
            }
        }
        else  // 按钮被按下
        {
            OnEventFunc(DOWN);
            pressTime = timer;
        }
        lastPinIO = pinIO;
    }

    // 如果等待双击的单击超过双击时间窗口，触发单击事件
    if (isSingleClickPending && timer - lastReleaseTime > doubleClickTime)
    {
        OnEventFunc(CLICK);
        isSingleClickPending = false;  // 清除单击等待状态
    }
}

void ButtonBase::SetOnEventListener(void (* _callback)(Event))
{
    lastPinIO =  ReadButtonPinIO(id);

    OnEventFunc = _callback;
}
