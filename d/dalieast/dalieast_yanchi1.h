//yanchi1.h

//Sample for room: ������سص̰�1
//coded by zouwenbin
//data: 2000-11-23

RESIDENT_BEGIN(CRDaliEast_yanchi1);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "������سص̰�1");

	set("resident", "��٤��");

	add_npc("pub_girl1");        // zdn 2001-07-12   add

	add_door("����ǵ��", "����ǵ��", "������سص̰�1");
	add_door("����ǽ�֭����", "����ǽ�֭����", "������سص̰�1");
	add_door("������سص̰�2", "������سص̰�2", "������سص̰�1");

	set("long", "�����غ��̰���ֲ��ɫ����ܰ�������ֳơ�����ӡ���������һ����֧���̰����ֻ�ɫ��ӭ�������ʳơ�����ӡ������֭�ӡ�����ͬΪ��صĳ�ˮ�ڣ��ֳƺ��ڡ�" );
	
};


RESIDENT_END;
