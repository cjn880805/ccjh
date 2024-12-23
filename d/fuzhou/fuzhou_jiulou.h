//jiulou.h

//Sample for room: ζ��ζ
//coded by zouwenbin
//data: 2000-11-13

ROOM_BEGIN(CRfuzhou_jiulou);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "ζ��ζ");

	//add npcs into the room
//	add_npc("pub_xiaoer3");
	
	add_door("������", "������", "����ζ��ζ");

    set("long", "����¥��¥����Բ�������˲�֪�������ʽ���˾��Ǹ���һ�������κ������Ƕ�һ���������ﳢ�������������ֺ��ļ����˸�ʽ�˵ȡ���С��������ȥ��æ���к����ˡ�ǽ�Ϲ��ż۸�����(paizi)��" );
	
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
