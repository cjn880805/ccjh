//road1.h

//Sample for room: ����ǹٵ�1
//coded by zouwenbin
//data: 2000-11-24

RESIDENT_BEGIN(CRDaLiNorth_road1);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "����ǹٵ�1");

	set("resident", "��گ");

	add_npc("pub_girl1");
	add_npc("pub_jianke");          //add by zdn 2001-07-13

	add_door("����ǹٵ�2", "����ǹٵ�2", "����ǹٵ�1");
	add_door("������ʯ��", "������ʯ��", "����ǹٵ�1");

	set("long", "����һ��������᫵�ɽ����·��������ԭͨ�����Ĺٵ����˴������ϣ�������ȥ����ɽ·ͨ���ƹ�ɽ�����̶��ɴ����Ѵ��������ȥ�򱱲�Զ������������--����ɽ��");
};

RESIDENT_END;
