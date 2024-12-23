//hcazhaitang.h

//Sample for room:  ���һ�����ի��
//coded by zouwenbin
//data: 2000-11-30

ROOM_BEGIN(CREMei_hcazhaitang);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "���һ�����ի��");


	CBox * box = Add_Box();
	box->add_object("qingshui_hulu", 2);	
	box->set_name( "����");
	
	add_npc("emei_feng");

	add_door("���һ����ֶ���2", "���һ����ֶ���2", "���һ�����ի��");
	add_door("���һ����ִ��۱���", "���һ����ִ��۱���", "���һ�����ի��");

	set("long","������Ƕ��һ����ֵ�ի�á�ի��������˳����Ĳ����ͳ��ʣ���λСʦ̫������æµ�Ų�����ի�����ϰ��˼��趹��������������Լ���Ѽ����ζ��ʳ��ի�ú�����һ����ͨ�������ִ���䣬���ߵ�����ͨ��㳡��");
    
    set("sleep_room", 1);

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
