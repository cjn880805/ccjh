//xiaodao.h

//Sample for room: ��ľ���ּ�С��
//coded by zouwenbin
//data: 2000-11-16

ROOM_BEGIN(CRHeiMuYa_xiaodao);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "��ľ���ּ�С��");

       add_npc("pub_menmian");         //add by zdn 2001-07-14


	add_door("��ľ����ʯ��", "��ľ����ʯ��", "��ľ���ּ�С��");
	add_door("��ľ��ɽ��", "��ľ��ɽ��", "��ľ���ּ�С��");
	add_door("��ľ�°׻��ô���", "��ľ�°׻��ô���", "��ľ���ּ�С��");

};


ROOM_END;
