# higv-demo

Middleware_V2.0.2.1

目录结构

|- api-demo
|- xml-demo
|- lib
|- resource
|--|-- fonts
|--|-- images
|--|-- pinyin

``` bash
mkdir build && cd build
cmake .. -DCMAKE_BUILD_TYPE=Debug -DCMAKE_TOOLCHAIN_FILE:string=../arm-linux.cmake && make && make install
```

Tips

- 任何控件必须设置皮肤属性，因为皮肤属性是必须的，不然解析 bin 文件的时候会报错，导致程序退出

- 所有的资源 ID 不能重复，复制粘贴的要注意了~

- HiBuilder 中皮肤显示是平铺，实际皮肤默认是缩放

- 不要使用 Hi Builder IDE 生成 bin 文件，使用 Linux 下的 xml2bin

- 使用控件前一定要看`标签使用指南`文档，查看那些属性是必须的

## 关于控件背景穿透窗口

控件没有设置背景颜色或者图片，isnodrawbg 设置成 yes

## 控件设置皮肤边框，右边框穿透，还有 Label 右边框穿透

这是 higv BUG 🐛

1. 联系海思工作人员
2. Label 可以使用其他控件替代，比如 button

## 颜色无法显示

检测是否是 ARGB，A 是透明度，0xFF000000 黑色，0x00000000 完全透明黑色，0x801400FA 透明度 50% 蓝色

## ## 使用 Edit 控件后生成 xml2bin 报错

HiBuilder 在 Edit 控件自动生成 ispassword 属性，貌似当前 xml2bin 工具还不支持这个属性，手动在 xml 删除这个属性

## Edit 控件运行中报错溢出

检查 maxlength 属性是否足够长

## 符号软键盘无法正常使用

点击按钮后符号软键盘消失，然后自动切换到英文软键盘，无法输入字符

使用 HI_GV_IMEWindow_STANDARD_A 、HI_GV_IMEWindow_STANDARD_B 进行替换，不要使用 HI_GV_IMEWindow_SYBMOL

## 软键盘输出 Soft keyboard window will goes off layer ，错误码 -1

这是 BUG 🐛 ，因为 Pinyin 输入法选择框溢出导致，可以忽略

## 软键盘 Pinyin 输入法选择框位置不对

这是 BUG 🐛

## 设置控件文本后，之前的文本没有清除

这是 BUG 🐛

可以手动刷新，先父容器在刷新自己

``` c++
HI_GV_Widget_GetParent(self, &parent);
if(parent != HI_NULL) {
    HI_GV_Widget_Paint(parent, NULL);
}
HI_GV_Widget_Paint(self, NULL); // or HI_GV_Widget_Update(self, NULL)
```

## HI_GV_Widget_SetTextByID 不工作

这里的 id 是要用 `HI_GV_FontSet_Create` api 创建返回后的 id，
xml2bin 并没有生成关于语言的资源，也许这是一个 BUG 🐛

## clock 控件显示错误，直接显示 UTC 时间 (1970 年)  没有进行转换普通时间

``` xml
<timefmt
	id="TIMEFORMAT_SIMPLE"
	en="[yyyy]/[MM]/[dd] [HH]:[mm]:[ss]"
	zh_CN="[yyyy]/[MM]/[dd] [HH]:[mm]:[ss]"/>
```

``` c++
    time_t t = time(NULL);
    HI_GV_Clock_SetUTC(widgetHandle, t);
    HI_GV_Widget_Paint(widgetHandle, NULL);
```

这是一个 BUG 🐛

## ListBox 布局问题

高度是根据行数决定的，设置10行不一定要给10行数据，也可以给1行数据

列的布局，新版本 xml 中有边距属性可以设置，但是提供 ide 和文档中没有描述

可以设置空的列来实现布局

``` xml
<listcol
    id="UI_PAGE_ABOUT_LISTBOX1_LISTCOL_NULL1"
    coltype="text"
    colwidth="20"
    colbinddb="no"
    coldbindex=""
    colalignment="hcenter|vcenter"
/>
```

## ListBox 列字体颜色显示异常

第一列设置颜色后，第二列第一行会显示第一列的字体颜色，然后才显示第二列自己的颜色

这是一个 BUG 🐛

