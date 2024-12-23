//xiaoba.h

//Sample for room: ����С��
//coded by zouwenbin
//data: 2000-11-17

ROOM_BEGIN(CRLingZhou_xiaoba);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "����С��");
	
	add_npc("pub_flowerg");    //add by zdn 2001-07-14


	add_door("���ݻ���̲", "���ݻ���̲", "����С��");
	add_door("������ͭϿ", "������ͭϿ", "����С��");

	set("long", "�����ǻƺӱߵ�һ��С֧����������ƺӻ�ϵĵط������ذ���Ϊ�˷�ֹ�ƺӵ���ɳ����������Ӷ�����������һ��СС��ʯ�ӣ�С�Ӳ��ߣ�������йɳ�Ķ���һ�Ƚ�ʵ��ʯբ�ţ������ǽ�����������բ�ŵ�������С��ʹ�ô����������İ��������˻ƺ���ɳ�����š� �ϱ��Ǻ�Ժ,����Щ�������ϻ������ǵ�ʿ����Ϣ�ĵط�����Ժ����һ�ھ�����������ȥ�е�����");  
	
};

virtual int do_look(CChar * me)
{
	say("�����ǻƺӱߵ�һ��С֧����������ƺӻ�ϵĵط������ذ���Ϊ�˷�ֹ�ƺӵ���ɳ����������Ӷ�����������һ��СС��ʯ�ӣ�С�Ӳ��ߣ�������йɳ�Ķ���һ�Ƚ�ʵ��ʯբ�ţ������ǽ�����������բ�ŵ�������С��ʹ�ô����������İ��������˻ƺ���ɳ�����š�", me);
	say("�ϱ��Ǻ�Ժ,����Щ�������ϻ������ǵ�ʿ����Ϣ�ĵط�����Ժ����һ�ھ�����������ȥ�е�������", me);
	SendMenu(me);
	return 1;
}
ROOM_END;