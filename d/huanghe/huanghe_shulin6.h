//shulin6.h

//Sample for room: �ƺ�����6
//coded by zouwenbin
//data: 2000-11-27

CHANGAN_BEGIN(CRHuangHe_shulin6);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "�ƺ�����6");
	
	add_npc("animal_snake");          // add by zdn 2001-07-14

	add_door("�ƺ�����5", "�ƺ�����5", "�ƺ�����6");

	set("long","��������߰�����ֻ������ͷ���ϴ���һЩ�����������ż����ï�ܵ�Ҷ��͸����һ�߹������Ҷ�ڷ��衣��ľ���õ���ζ�����ᴫ��Ұ�޵�Х��ʹ�˲�����ԥ��ǰ���ĽŲ���");
	

/*****************************************************
	set("exits", ([
		"east"  : __DIR__"shulin5",
	]));
********************************************/
};


CHANGAN_END;
