//yuanzi.h

//Sample for room: ����ɽԺ��
//coded by zouwenbin
//data: 2000-11-28

ROOM_BEGIN(CRBaiTuoShan_yuanzi);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "����ɽԺ��");



	add_door("����ɽ����", "����ɽ����", "����ɽԺ��");
	add_door("����ɽ����", "����ɽ����", "����ɽԺ��");
	add_door("����ɽ������", "����ɽ������", "����ɽԺ��");
	add_door("����ɽ������", "����ɽ������", "����ɽԺ��");

	set("long", "����һ����Ժ�ӣ���ɨ��һ����Ⱦ������װ����������񣬴������¡������������⡣������һ�䴢���ң�����(door)�ر��š������ǡ�����ɽׯ���Ĵ������ϱ߾��Ǵ����ˡ�.������������������գ����Բ��������˴����");
    
    set_temp("lock",1);

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
