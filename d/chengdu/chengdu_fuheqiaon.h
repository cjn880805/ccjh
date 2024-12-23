//fuheqiaon.h

//Sample for room: ������
//coded by zouwenbin
//data: 2000-11-13

ROOM_BEGIN(CRChengDu_fuheqiaon);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "������");

	add_npc("pub_nieyinnang");
	add_npc("pub_daoke");
	add_npc("pub_punk");         //zdn 2001-07-12  add
	add_npc("pub_simingtoutuo");

	add_door("�ɶ���", "�ɶ���", "�ɶ�������");
	add_door("�����ʯ���", "�����ʯ���", "�ɶ�������");

	set("long",	"�����ǳɶ������⸮���š��ɶ����Ǵ����׸���ȴ���տ��أ�һ���з������ɶ�ƽԭ����ʹ��������ˮ�ǣ�Ҳ��ֻ�е���Է��ȱ���ѡ���ˡ�"	);

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
