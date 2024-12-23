//xiaojiaqiao.h

//Sample for room: 黄河萧家桥
//coded by zouwenbin
//data: 2000-11-27

CHANGAN_BEGIN(CRHuangHe_xiaojiaqiao);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "黄河萧家桥");


	add_door("黄河古浪", "黄河古浪", "黄河萧家桥");

	set("long","在兰州和古浪中间，纪永河水咆哮而过，河水湍激，河床最宽处九丈四尺，窄处七丈余，度船难过。相传汉年间，本地一位萧姓大财主，穷六年之功，遍集巧匠，费尽家私，方建成桥，欲到兰州，必先度本桥。");
	
};


CHANGAN_END;
