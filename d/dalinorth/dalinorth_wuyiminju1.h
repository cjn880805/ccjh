//wuyiminju1.h

//Sample for room: ������������1
//coded by zouwenbin
//data: 2000-11-24

ROOM_BEGIN(CRDaLiNorth_wuyiminju1);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "������������1");
	
	add_npc("dali_fangshanu");        //add by zdn 2001-07-20


	add_door("��������ɴ���", "��������ɴ���", "������������1");

	set("long", "����һ��������ķ��ݡ�������ӵĽ��غ����򽲾���������ɽ�ƣ�һ����ʯΪǽ�ͻ�����ľΪ�����ṹ���ºͺ��˷�����£�����ƽ����ʯ��Χǽ�����Ժ����һȦ������ţ����С�");
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
