//luojiadian.h

//Sample for room: �������٤��
//coded by zouwenbin
//data: 2000-11-23

RESIDENT_BEGIN(CRDaliEast_luojiadian);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "�������٤��");

	set("resident", "��٤��");

	add_npc("pub_nongfu");    // add by zdn 2001-07-12 

	add_door("������سص̰�3", "������سص̰�3", "�������٤��");
	add_door("����ǵ���ذ�1", "����ǵ���ذ�1", "�������٤��");
	add_door("�����ũ��2", "�����ũ��2", "�������٤��");

	set("long", "�����ǵ�صĶ��ϣ���ôЩ������٤����۾ӵĵط���ôЩ���������ġ�����ϲ��ƽԭ��ˮ������ˮ��ƽԭ���ӣ���Ϊ���顱���������������֣���ȱ��ס���٤��һ�����䣬��٤���Ǹ��൱������ӣ�����������������θ���" );
	
};


RESIDENT_END;
