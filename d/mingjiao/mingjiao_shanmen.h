//shanmen.h
//Sample for room: ����
//coded by zouwenbin
//data: 2000-11-16

ROOM_BEGIN(CRMingJiao_shanmen);

virtual void create()			//Call it when Room Create
{

	//set name of our room

	set_name( "����ɽ��");
	
	add_npc("pub_menwei1");	
	add_npc("pub_menwei1");	
	add_npc("mingjiao_jieyinshi");	
	add_npc("zm_mingjiao");	

	add_item("was_mache");
	set("count",1);

	add_door("������ʯ���2", "������ʯ���2", "����ɽ��");
	add_door("������ʯ���3", "������ʯ���3", "����ɽ��");

	set("long", "һ���޴����Ȼʯ�ź������Ƭɽ��֮�䣬ʯ�����Ϸ����̷�������������֣������̡����ּ���Щ���䣬����ȥ�����Զ����λ��ʮ����Ĵ��ֳָֽ�����ɽ�����ࡣ    ��ǫִ���������á�");
    
};

ROOM_END;
