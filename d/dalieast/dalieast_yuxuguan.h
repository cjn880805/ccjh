//yuxuguan.h

//Sample for room: �����
//coded by zouwenbin
//data: 2000-11-15

ROOM_BEGIN(CRDaliEast_yuxuguan);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "�����");

	add_npc("dali_daobaifeng");	

	add_door("����������ǰ", "����������ǰ", "����������");

	set("long", "�������ʮ����죬���й����Ź��ϡ�������������õȰ��ɵ�����������ƣ������ϰ���Щ��ҡ����з��˼������š��Ա�һ��С����������Σ�������ɢ����Ϣ����ͽ�ĵط���" );

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
