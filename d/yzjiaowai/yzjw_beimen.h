//beimen.h

//Sample for room:  ���ݱ���
//coded by zwb
//data: 2000-11-22

ROOM_BEGIN(CRYZJW_beimen);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "���ݱ���");

	add_npc("pub_wujiang");
	add_npc("pub_bing");
	add_npc("pub_beibeibei");

	add_door("���ݱ����","���ݱ����","���ݱ���");
	add_door("��������","��������","���ݱ���");

    set("long","���Ǳ����ţ���Ϊ����ʧ�𣬵����ڳ�ǽ���Ǻں����ģ���˰�ֽ���ֵĹٸ���ʾ(gaoshi)���Ե��ر����ۡ�������һƬ��ɽ���룬һ������С����ɽ�����Ѷ��ϡ�");

};


ROOM_END;
