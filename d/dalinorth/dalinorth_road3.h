//road3.h

//Sample for room: ����ǹٵ�3
//coded by zouwenbin
//data: 2000-11-24

RESIDENT_BEGIN(CRDaLiNorth_road3);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "����ǹٵ�3");

	set("resident", "��گ");

	//add npcs into the room
	add_npc("pub_girl1");
	
	add_door("�������گ�»���", "�������گ�»���", "����ǹٵ�3");
	add_door("����ǹٵ�2", "����ǹٵ�2", "����ǹٵ�3");

	set("long", "������һ����ʯ�ٵ��ϣ������Ѿ�����گ�����ˣ�·��ʱʱ���Կ�����ɫ�����������������������䲻����·��վ��Щ�����λ��޵İ���Ů�ӣ�����һ�������µ��Եø�����������ȥ���ϼ��Ǵ�������ؿ�̫�ͳǣ��عٵ��򶫱��ɴ���ԭ��(mountain)�������಻���Ĵ�ɭ��(forest)��--����ɽ��");
	
};


RESIDENT_END;
