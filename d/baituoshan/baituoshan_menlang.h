//menlang.h

//Sample for room: ����ɽ����
//coded by zouwenbin
//data: 2000-11-28

ROOM_BEGIN(CRBaiTuoShan_menlang);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "����ɽ����");

	//add npcs into the room
	add_npc("pub_guanjia");
	
	add_door("����ɽ��԰", "����ɽ��԰", "����ɽ����");
	add_door("����ɽ������", "����ɽ������", "����ɽ����");

	set("long", "���Ǹ����ȣ����ȵķ����Ϲ���һ������Сͭ��������з�����ද����������.������Ů����������Ϸ���������������Ļ���������ͨ��ɽׯ�����ط��������ǳ����������ǰ���ɽ������ŷ���ˡ������ң��������ţ���֪�����ڲ��ڡ�");

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
