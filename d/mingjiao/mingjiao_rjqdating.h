//rjqdating.h



//Sample for room: ��������

//coded by zouwenbin

//data: 2000-11-16



ROOM_BEGIN(CRMingJiao_rjqdating);



virtual void create()			//Call it when Room Create

{

	//set name of our room

	set_name( "������������");

	add_npc("pub_liuyun");

	add_npc("mingjiao_zhuangzheng");

	add_door("������ʯ���5", "������ʯ���5", "������������");

	set("long", "���������Ĵ�������Ȼ��������֮�ˣ�����ȴ���õù�ɫ���㣬�Գ����������ڲ�ͬ�������������һ�����ң������ĸ��̽���֡�������硱��һ�ٶ�ʮ��ǰ���������������ɹž���һ����ս����������������£����߰ˡ��ţ�������������������ڣ�������Դ�Ϊ����֮�ס���������в輸�����������ʹׯ�������������ڶ�һ�����" );

/*****************************************************

	set("exits", ([

		"south" : __DIR__"rjqyuan",

	]));

//	set("outdoors", "mingjiao");

        set("objects",([

                __DIR__"npc/zhuangzheng":1,

//              "/kungfu/class/mingjiao/zhuangzheng":1,

//		"/kungfu/class/mingjiao/yangxiao":1,

//	        "/kungfu/class/mingjiao/fanyao":1,

//	        "/kungfu/class/mingjiao/yintianzheng":1,

//              "/kungfu/class/mingjiao/xiexun":1,

//	        "/kungfu/class/mingjiao/xuan-nan":1,

//              "/kungfu/class/mingjiao/weiyixiao":1,

	]));

********************************************/

};





ROOM_END;
