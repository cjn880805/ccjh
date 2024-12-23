//yaofang.h

//Sample for room: ҩ��
//coded by zouwenbin
//data: 2000-11-16

ROOM_BEGIN(CRBaiTuoShan_yaofang);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "ҩ��");

	//add npcs into the room
	add_npc("pub_xiaoqing");

	CBox * box = Add_Box();
	box->add_object("baiyunwan", 1);	
	box->set_name( "����");	
	
	add_door("����ɽ����", "����ɽ����", "����ɽҩ��");

	set("long", "�����Ǽ�ҩ������ǽ����һֻ��ҩ���������������ӣ��ϱ߰�������ҩ�õ�ƿƿ�޹ޡ�����һ��ҩƿ(bottle)��ֻװ����ˮ����ҩʦ��λС����,�������﷢������֪����ʲô�����������ɵĳ��ȡ�");  

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
