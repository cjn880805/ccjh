//huanshi.h

//Sample for room: ��ʩˮ��
//coded by zouwenbin
//data: 2000-11-13

ROOM_BEGIN(CRyanziwu_huanshi);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "��ʩˮ��");

	CBox * box = Add_Box();
	box->set_name( "���");
	
	box->add_object("book_iron");	
	box->add_object("book_paper");	
	box->add_object("book_silk");	
	box->add_object("book_stone");	
	
	//added by lanwood 2001-02-24 ����һ���飺�Ṧƪ
	box->add_object("dodgebook");

	box->Locked("����", 3000000);

	add_door("���������¾�", "���������¾�", "�����뻹ʩˮ��");

    set("long", "����������ܣ����ϰ�������Ĺžɵ��鼮�����Ͼ����б�ǩ�������Ľ�����������������ռ����۶��ɵ���ѧ���⡣" );
    
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
