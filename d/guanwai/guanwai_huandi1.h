//huandi1.h
//Sample for room: ��·1
//coded by zouwenbin
//data: 2000-12-1

RESIDENT_BEGIN(CRGuanWai_huandi1);

virtual void create()			//Call it when Room Create

{

	//set name of our room

	set_name( "��·1");

	set("resident", "������Զ");
	
	add_npc("guanwai_wan");    //// add by zdn 2001-07-13
	
	add_door("������Զ", "������Զ", "�����·1");

	add_door("�����·2", "�����·2", "�����·1");

    set("long","���ǳǶ���һ����·��·�����ҵĳ�����ϥ�ĻĲݣ�Զ������һ�ˡ����Ըɿݵ������������˳�Ⱥ����ѻ���������������ڻ�Ұ��ԶԶ��ȥ��һ�������ľ���" );


};


RESIDENT_END;
