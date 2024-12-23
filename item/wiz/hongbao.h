//hongbao.h 压岁红包
//muri 2002-2-5

ITEM_BEGIN(CIhongbao)

void create(int nFlag = 0)	
{
	set_name("压岁红包", "hong bao");
	set_weight(10);
    set("no_give", "好大方的人呀，不如给我吧！");
    set("value", 0l);
	set("no_steal", 1);
	set("no_beg", 1);
    set("no_put", 1);
    set("no_drop","这么珍贵的东西你也扔？！");

	set("long", "这是金智塔公司赠送给新年钟声敲响时，仍然在线奋斗的朋友们的压岁红包。");
	set("unit", "个");	

	set("open_msg", "小心翼翼的撕开了红包封口");
}

int Can_Use()
{
	return 1;
}
 
int do_use(CChar * me, CContainer * who)
{
	char msg[255];

	message_vision(snprintf(msg, 255, "$HIY$N%s，从红包中倒出了一堆的金币，美滋滋的数了起来...", querystr("open_msg")), me);
	tell_object(me,snprintf(msg, 255, "1个金币、2个金币、3个金币、4个金币......") );
	tell_object(me,snprintf(msg, 255, "108个金币、118个金币、128个金币、138个金币......"));
	tell_object(me,snprintf(msg, 255, "1088个金币、1188个金币、1288个金币、1388个金币......"));
	tell_object(me,snprintf(msg, 255, "10888个金币、11888个金币、12888个金币、13888个金币......"));
	tell_object(me,snprintf(msg, 255, "$HIY你终于数完了面前的这堆金币，满意的点了点头，总共收到了16888个金币的一个红包"));
	CMoney::Pay_Player(me, 16888);
	destruct(this);
	message_vision(snprintf(msg, 255, "$HIY$N抖了抖红包，发现里面还有一些零零碎碎的东西，顺手就抓了出来。"),  me);
	load_item("fuxingjiou")->move(me);
	load_item("shouxingtao")->move(me);
	load_item("lvxingguo")->move(me);
	tell_object(me,snprintf(msg, 255, "你获得了一杯福星酒、一颗禄星果，一个寿星桃。"));
	return 1;

}

void owner_is_killed(CChar * me)
{
	destruct(this);
}

ITEM_END;




