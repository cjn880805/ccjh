//qianzhuang.h

//Sample for room: Ǯׯ
//coded by Fisho
//data: 2000-11-2

ROOM_BEGIN(CRBeiJing_qianzhuang);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "Ǯׯ");

	add_npc("pub_zaochongzha");
	add_door("��������", "��������", "����Ǯׯ");

	set("long", "����һ�����ֺŵ�Ǯׯ�����м��������ʷ����ȫ�����ض��зֵꡣ�����е���Ʊ�����ǳ��ã�ͨ��ȫ�����������ߵ�������κ�һ����ׯ�ֵ궼���������ȡ��ǽ�Ϲ���һ������(paizi)��" );
	
	set("no_fight", 1);
	set("no_beg", 1);
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
