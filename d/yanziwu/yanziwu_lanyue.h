//lanyue.h

//Sample for room: ���¾�
//coded by zouwenbin
//data: 2000-11-13

ROOM_BEGIN(CRyanziwu_lanyue);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "���¾�");
	
	add_npc("murong_fu"); 
	add_npc("murong_azhu");      //add by zdn 2001-07-20

	add_door("�����뺲ī����", "�����뺲ī����", "���������¾�");
	add_door("�����뻹ʩˮ��", "�����뻹ʩˮ��", "���������¾�");

    set("long", "����Ľ�ݹ��ӵ����ң����г�����ͨ����ʰ����Ϊ���࣬�ݽ�һ��ï���辰���ú�����ʢ�������¹�Ӵ�����������������⣬���������һ��������" );
    
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
