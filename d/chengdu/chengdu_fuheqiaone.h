//fuheqiaone.h

//Sample for room: ��������
//coded by zouwenbin
//data: 2000-11-13

ROOM_BEGIN(CRChengDu_fuheqiaone);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "��������");

	add_npc("pub_girl1");
	add_npc("pub_playboy");        //zdn 2001-07-12  add

	add_door("�ɶ���", "�ɶ���", "�ɶ���������");
	add_door("�䵱������", "�䵱������", "�ɶ���������");

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
