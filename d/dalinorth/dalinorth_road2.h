//road2.h

//Sample for room: ����ǹٵ�2
//coded by zouwenbin
//data: 2000-11-24

RESIDENT_BEGIN(CRDaLiNorth_road2);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "����ǹٵ�2");

	set("resident", "��گ");

	add_npc("pub_playboy");
	add_npc("pub_daoke");     // add by zdn 2001-07-13

	add_door("����ǹٵ�3", "����ǹٵ�3", "����ǹٵ�2");
	add_door("����ǹٵ�1", "����ǹٵ�1", "����ǹٵ�2");

	set("long", "������᫵���·��Խ���ϵ�ɽ�������ϱ��������Ѿ������ƹ󣬺��ɽ����������������һ����Ȼ���ϸ������Ѻ����С����������ϴ���ɽ�����ɴ������ȥ��ɽ�����츮֮������·���Զ���һ���޼ʵĳ�ɽ����(mountain)�������಻���Ĵ�ɭ��(forest)��--����ɽ��");
	
};


RESIDENT_END;
