//anjinmenkey.h
ITEM_BEGIN(CImupai)

virtual void create(int nFlag = 0)		
{
	set_name("��ʾ��");
	set("no_get", "�����Ʋ���Ҳ�����ߣ�������Ҳ̫�����˰ɡ�");

};

virtual int do_look(CChar * me)
{
	say("���洳��֮ð���ߣ����������������꣬ʼ������ɴ��ơ�ֻ�����в����е��и�����Ϲ����������и�ʽ���¿��µĻ����󷨡�", me);
	say("�������У�Ψ�д�����ȷ�Ļ��أ����ɽ������һ�㡣���򲻽�����ǰ�����������������˺���", me);
	say("���Դ˾�ʾ�����������������ء�", me);
	SendMenu(me);

	return 1;
}
ITEM_END;




