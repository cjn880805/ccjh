//yanchi3.h

//Sample for room: ������سص̰�3
//coded by zouwenbin
//data: 2000-11-23

RESIDENT_BEGIN(CRDaliEast_yanchi3);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "������سص̰�3");

	set("resident", "��٤��");

	//add npcs into the room
	add_npc("pub_guigongzi");
	add_npc("pub_enu");

	add_door("�������٤��", "�������٤��", "������سص̰�3");
	add_door("������سص̰�2", "������سص̰�2", "������سص̰�3");

	set("long", "�����ǵ���ο;ۼ�֮������۷���������ʱʱ������ʤ����ˮ翰��ĵ�أ����͡���ɲ�ڵᲨ�����֡�������������ͣ�۹ٶɣ����Ƹ�ʫ������֮Ϊ��ͣ���̻ᡱ������Ķ��ֲʺ硢��ɽ���ꡢ������𸡢��ϼ���졢�鷫ԶӰ���޲��������������ܡ�" );

};


RESIDENT_END;
