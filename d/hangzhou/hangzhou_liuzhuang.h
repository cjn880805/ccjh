//liuzhuang.h

//Sample for room: ������ׯ
//coded by zouwenbin
//data: 2000-11-24

RESIDENT_BEGIN(CRhangzhou_liuzhuang);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "������ׯ");

	set("resident", "����");
	set("capacity", 25);

	//add npcs into the room
	add_npc("pub_guanjia");
	add_npc("pub_jiading");
	add_npc("pub_jiading");

	add_door("�����غ����3", "�����غ����3", "������ׯ");

	set("long","ׯ԰�Ĵ������ǡ���ׯ���������֡�����(gate)���գ����澲���ĵ�һ��������û�С�(pond)���������ǳ�����ɽ��·��");

};

RESIDENT_END;
