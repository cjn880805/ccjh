//qingxinquan.h

//Sample for room: ��������Ȫ
//coded by zouwenbin
//data: 2000-11-17

ROOM_BEGIN(CRLingZhou_qingxinquan);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "��������Ȫ");
	
	add_npc("pub_xiaowei");            //add by zdn 200-07-14

	add_door("�������пյ�", "�������пյ�", "��������Ȫ");
//	add_door("������������", "������������", "��������Ȫ");

	set("long", "����ɽ�е�һ����Ȫ��λ���ֳ������ɽ���ϣ���Χ�Ǵ��̵�������������ɽȪˮ��Ȫ�ۻ�����ӿ�����۳�һ��С̶��С̶ˮ���������ɽ���Ա�һ��С·ͨ��ɽ�¡�");  
	
	set("resource/water", 1);

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
