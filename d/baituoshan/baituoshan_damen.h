//damen.h

//Sample for room: ����ɽ����
//coded by zouwenbin
//data: 2000-11-28

ROOM_BEGIN(CRBaiTuoShan_damen);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "����ɽ����");

	//add npcs into the room
	add_npc("pub_menwei1");
	
	add_door("����ɽʯ��", "����ɽʯ��", "����ɽ����");
	add_door("����ɽԺ��", "����ɽԺ��", "����ɽ����");

	set("long", "������������µġ�����ɽׯ���Ĵ��š��������ϵ����̷��ۼ���أ���֪�����Ŷ����ܹ��ɽ�����Ѫ�����Գ�ׯ���ĸ������Թ���ǰ���Ҹ�����һֻ����ׯ�ϵ�ʯʨ�ӡ�(door)�ر��š������ǡ�����ɽׯ���Ĵ������ϱ߾��Ǵ����ˡ�.������������������գ����Բ��������˴����");

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
