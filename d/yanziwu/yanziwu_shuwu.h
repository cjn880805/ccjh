//yabziwu_shuwu.h

//Sample for room: ��ī����
//coded by zouwenbin
//data: 2000-11-13

ROOM_BEGIN(CRyanziwu_shuwu);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "��ī����");
	
	add_npc("murong_xiansheng"); 
	add_npc("murong_tang");        //add by zdn 2001-07-20      

	add_door("������κϾ�", "������κϾ�", "�����뺲ī����");
	add_door("���������¾�","���������¾�","�����뺲ī����");

    
	set("long","����һ�ܼ������ɵ������ǽ����������ϰ����˾�ʷ�伮��������������һ����������������㱸����īֽ��һӦ��ȫ��ǽ�Ϲ���һ������(tiaofu)������������Ľ�ݹ��ӳ����������д�֡�");

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
