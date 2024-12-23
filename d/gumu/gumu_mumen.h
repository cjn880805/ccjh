//gumu_mumen.h

//Sample for room: ��ĹĹ��
//coded by zouwenbin
//data: 2000-11-17

ROOM_BEGIN(CRGuMu_mumen);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "��ĹĹ��");

	add_npc("gumu_sun");

	add_door("��Ĺ�ݵ�", "��Ĺ�ݵ�", "��ĹĹ��");
	add_door("��Ĺǰ��", "��Ĺǰ��", "��ĹĹ��");
	add_door("��Ĺ��ɳ��", "��Ĺ��ɳ��", "��ĹĹ��");

    set("long","���߹��˲ݵأ���ǰͻȻ��һƬ�����أ�ͻأ��������һ����Ĺ��Ĺ������ʯͷ�Ѿ��ವ�ˣ����ĳ�����������Ĺ��Ĺǰû��������Ҳû���κεı�ǣ���֪������ǰ����λ�����󳼵�ĹѨ��Ĺ�ſڱ�һ�������Ĵ�ʯͷ(shi)��յ�˿����͸��" );
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
