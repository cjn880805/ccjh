//qianzhuang.h

//Sample for room: �������Ǯׯ
//coded by Fisho
//data: 2000-11-3

CHANGAN_BEGIN(CRChangAn_qianzhuang);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "�������Ǯׯ");

	//add npcs into the room
	//add_npc("tiesuanpan");
	
	add_door("����", "����", "�������Ǯׯ");

	set("long", "����һ�����ֺŵ�Ǯׯ�����ϰ���ɽ���ˣ����Ǯׯ������үү��үү��үү��үү�Ǳ���ʼ����һֱ��������������ǳ��ã���ȫ�����ض��зֵꡣ�����е���Ʊͨ��ȫ����Ǯׯ���ſڹ���һ������(paizi)��" );
	set("no_fight", 1);

};

virtual int do_look(CChar * me)
{
	char msg[255];
	snprintf(msg, 255, "%s", querystr("long"));
	say(msg, me);
	SendMenu(me);
	return 1;
}


CHANGAN_END;
