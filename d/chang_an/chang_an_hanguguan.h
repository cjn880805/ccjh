//hanguguan.h

//Sample for room: ���ȹ�
//coded by Fisho
//data: 2000-11-3

CHANGAN_BEGIN(CRChangAn_hanguguan);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "���ȹ�");
	
	add_npc("pub_playboy");  //2001-07-12 zdn add

	add_door("������ٵ�2", "������ٵ�2", "�������ȹ�");
	add_door("���������", "���������", "�������ȹ�");
	add_door("��������", "��������", "�������ȹ�");

	set("long", "������ǹź��Źء���������ɽ���������򣬹�����С�����ǿ��һ��֮�أ��ƹض������������Զ�������ɨ���£�������Ϊ���ݴˣ����ɹ����˿��أ���������ʤ֮������������������Ҳ���ڴ�����������¾���ǧ�����£��������ж�������" );
	
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
