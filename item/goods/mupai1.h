//anjinmenkey.h
ITEM_BEGIN(CImupai1)

virtual void create(int nFlag = 0)		
{
	set_name("��ʾ��");
	set("no_get", "�����Ʋ���Ҳ�����ߣ�������Ҳ̫�����˰ɡ�");

};

virtual int do_look(CChar * me)
{
	say("���������", me);
	say("Ҫ���˸������⣺", me);
	say("��־��ң��Ź��Ų������ھ���һ�ӣ���ǰȡ����ʮ���壬�ַ����ҳ��ϣ�ʹ�ø����ݡ��ᡢб������֮�;�Ϊʮ�壬��ɴ������أ����ô˸�", me);
	say("��ʧ�����Σ�����˸���Ե�������ء�", me);
	/*
	if(me->query("xy/renwu6") && me->query("xy/renwu6_1"))
	{
	}
	*/
	SendMenu(me);

	return 1;
}
ITEM_END;




