//shilin2.h

//Sample for room: ����Ǻ�Ħ��ʯ��
//coded by zouwenbin
//data: 2000-11-24

ROOM_BEGIN(CRDaLiNorth_shilin2);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "����Ǻ�Ħ��ʯ��");

	//add npcs into the room
	add_npc("pub_tufei1");
	add_npc("pub_tufei1");
	add_npc("pub_tufei2");

	add_door("����ǳ���", "����ǳ���", "����Ǻ�Ħ��ʯ��");

	set("long", "����ʯ�ŷ��ʯ���ͣ�ʯ����ڹ��ӣ����ư��磬�����ŭ�γ�����𣬾���ϸ�µĶ������٣����������侳��̤ʯ�㣬��ʯ�ţ���Ұ�ݣ�̽���֣�����ɽ�����ڣ�Σʯɭɭ�����ԭҰ������ɽ�����󣬻������ƣ�һ��ǿ�ҵ�ɽҰζӭ��������������εĴ������Ȼ�������˶�Ŀһ�¡�");
	
};

virtual int do_look(CChar * me)
{
	char msg[255];
	snprintf(msg, 255, "%s", querystr("long"));
	say(msg, me);
	SendMenu(me);
	return 1;
}

ROOM_END;
