//wuqiku.h

//Sample for room: ������
//coded by zouwenbin
//data: 2000-11-14

ROOM_BEGIN(CRShaoLinSi_wuqiku);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "������");

	add_npc("shaolin_dao_chen");

	add_door("�����¶�����С��", "�����¶�����С��", "������������");
	add_door("�����·��߿�", "�����·��߿�", "������������");

	set("long", "����һ��ܴ�ķ��䣬��ǽ����ط���һ��������ӣ����ٹ����ų����ţ�¶������ĸ��ַ��ߣ�Ʒ��֮�࣬������ƽ������һλ����ɮ������ͷ����һ������Ļ��ߡ��������Ҳû��ע�⡣" );

};


ROOM_END;
