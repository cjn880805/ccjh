//tianlongsi.h

//Sample for room: ������
//coded by zouwenbin
//data: 2000-11-15

ROOM_BEGIN(CRDaLiNorth_tianlongsi);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "������");
	
	add_npc("pub_youke");
	add_npc("pub_jianke");     //add by zdn 2001-07-13
	add_npc("dali_pochen");    //add by zdn 2001-07-20

	add_door("����Ǻ�ʥ����", "����Ǻ�ʥ����", "����Ǳ�������");

//	set("long", "���Ż��۽��붴�ڣ��ػ����У����ã�����һ����Ȼ���ʣ�ʯ���飬ʯ��ʯ����������͸��������ʤ�����ձ�Ӱ�����´����ң�Ϫ�ƽ�ˮ�������ֺ���ʯ��δ䣬���Ŀɰ���" );
//	

/*****************************************************
	set("outdoors", "dali");
	set("exits",([ 
	    "out"      : __DIR__"changhu",
	]));

********************************************/
};


ROOM_END;
