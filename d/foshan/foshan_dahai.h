//dahai.h
//Sample for room: ��ɽ��
//coded by zwb
//data: 2000-11-23

ROOM_BEGIN(CRFoShan_dahai);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "��ɽ����");
	//add npcs into the room
	add_npc("pub_puren");
	add_door("��ɽ", "��ɽ", "��ɽ��");
	add_door("���͵���̲", "���͵���̲", "��ɽ��");

	set("long", "�����Ƿ�ɽ������š����������ϣ��͵����Ϻ�֮���ˡ�����һ��������Ĵ���Ƿ�ɽ�����Ҫ�ֵ���" );

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
