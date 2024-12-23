//baxian.h

//Sample for room: ���ɵ���
//coded by zouwenbin
//data: 2000-11-17

ROOM_BEGIN(CRLingZhou_baxian);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "���ɵ���");

	//add npcs into the room
	add_npc("wudang_laodaoshi");
	
	add_door("��������С·2", "��������С·2", "���ݰ��ɵ���");

	set("long", "�����ǰ��ɵ��ۣ����а��ɵ�����Ź��ϡ�������������Ȱ��ɵ������㰸���������ơ���ǽ���ż���̫ʦ�Σ����Ϸ��ż������š��������������ȣ������Ƕ���� �ϱ��Ǻ�Ժ,����Щ�������ϻ������ǵ�ʿ����Ϣ�ĵط�����Ժ����һ�ھ�����������ȥ�е�����");  
	set("no_fight",1);

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
