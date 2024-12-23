//hcahoudian.h

//Sample for room:  ���һ����ֺ��
//coded by zouwenbin
//data: 2000-11-30

ROOM_BEGIN(CREMei_hcahoudian);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "���һ����ֺ��");

	add_npc("emei_miejue");
	add_npc("emei_zhou");
	add_npc("zm_emei");

	add_door("���һ����ִ��۱���", "���һ����ִ��۱���", "���һ����ֺ��");

	set("long","���Ƕ���ɽ�����ֵĺ��Ƕ����������˴��̵��ӹ���ĵط������﹩��һ���������������Կ�ǽ���ż���̫ʦ�Σ����Ϸ��ż������š������������򼸸�Ů���Ӵ����书��");
    
    set("no_get_from", 1);
    set("no_get", 1);
    set("no_steal", 1);

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
