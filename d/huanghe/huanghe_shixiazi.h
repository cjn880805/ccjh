//shixiazi.h

//Sample for room: �ƺ�ʯϿ��
//coded by zouwenbin
//data: 2000-11-27

CHANGAN_BEGIN(CRHuangHe_shixiazi);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "�ƺ�ʯϿ��");

	CBox * box = Add_Box();
	box->add_object("eluanshi", 1);	
	box->set_name( "����");	
	
	add_npc("pub_poorman");
	add_npc("pub_punk");         //add by zdn 2001-07-14

	add_door("�ƺ�������", "�ƺ�������", "�ƺ�ʯϿ��");
	add_door("�ƺӱ�����", "�ƺӱ�����", "�ƺ�ʯϿ��");

	set("long","ʯϿ������ǰ�Ļƺӹʵ������ڱ���Ǵ��СС�Ķ���ʯ�����������ɸߵĸ��£�ǧ�����֣�������˵�����µĲ�ɣ��Ҫ�������õĻ������������𵽷ǳ�Ư�����ǳ������껨ʯ��");

/*****************************************************
	set("exits", ([
		"southwest" : __DIR__"tumenzi",
		"northeast" : __DIR__"bingcao",
	]));
	set("objects", ([
		"/d/city/obj/shitou" : 1,
		"/d/hangzhou/obj/eluanshi" :1,
	]));
********************************************/
};


CHANGAN_END;
