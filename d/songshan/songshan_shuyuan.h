//shuyuan.h

//Sample for room: ������Ժ
//coded by zouwenbin
//data: 2000-11-

ROOM_BEGIN(CRShongShan_shuyuan);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "������Ժ");
	
	add_npc("pub_shutong");         // add by zdn 2001-07-15


	add_door("��ɽɽ��2", "��ɽɽ��2", "��ɽ������Ժ");
	add_door("��ɽɽ��3", "��ɽɽ��3", "��ɽ������Ժ");

	set("long", "����ԭ�������¡������Ļ��������͸ĳ���������Ժ���������Ժ����´��Ժ����¹��Ժ�ϳ����� '�Ĵ���Ժ'�����γ��������ڴ˽�ѧ��Ժ���йŰ����꣬�����Ѳ�����ˣ����Ϊ�󽫾�������������������" );
	

/*****************************************************
	set("exits", ([
		"southdown" : __DIR__"shandao2",
		"northwest" : __DIR__"shandao3",
	]));
********************************************/
};


ROOM_END;
