//yuquan.h

//Sample for room: ��ȪԺ
//coded by zouwenbin
//data: 2000-11-17

ROOM_BEGIN(CRHuaShan_yuquan);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "��ȪԺ");
	
	add_npc("pub_baiyuer");

	add_door("��ɽ����", "��ɽ����", "��ɽ��ȪԺ");

	set("long", "�������ݺ����Ȫ�����������δ���ϣ�����ӵĵط�����Χ����ʮ��������٣�ز�ö��ˣ�֦���пգ�����������ƣ��ഫ��ϣ����������������ֲ��Ժ��������գ�Ȫʯ�续����ˮ�ӻأ��������ۡ�Ժ������Ȫһ�ɣ�Ȫˮ����������ɽ������������ͨ��������Ȫ����ȪԺ��˵�����");  

};


ROOM_END;
