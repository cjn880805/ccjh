//wangqing_shi.h ����ʯ
FOOD_BEGIN(CIwangqing_shi);

virtual void create(int nFlag = 0)		
{
	set_name( "����ʯ");	
	set_weight(700);
	set("unit", "��");
	set("long", "����һ��͸������ʯ����Ө��׺�������˫���ḧ��ʯ��������������Ĺ���һ����ɲ�Ǽ���˸����Ө����ʯ���棬����ڤڤ��");

};

virtual int do_use(CChar * me, CContainer * target)
{
	message_vision("$N���Ậס������ʯ����ʯ��˲�伴���ڻ�Ϊһ��Һ�壬����������С� ", me);
	if(me->querymap("couple"))
	{
		message_vision("$HIRǰ�����������̣�������������һ�ƺ���ϵ���ĺ��߽ڽڶ��䣬�Դ˺�����������������޹ϸ�\n$N��ϸƷ��һ������ɬ��Һ�壬ԭ������һ��Ϊ���������������ᣬ���۳�ʯ�����ڴ˿������ڻ��� ", me);
		CUser * targetx;
		char idd[255];
		snprintf(idd,255,"%s",me->querystr("couple/id"));
		targetx=find_online(idd);
		if (targetx)
		{
			tell_object(me, "������İ������������ϣ�����ʯʧȥ������Ч����");
			return 1;
		}
		else
		{
			char msg[255];
			targetx = add_user();
			targetx->set("id", me->querystr("couple/id"));
			targetx->LoadFromServer();

			me->set("last_couple_name",me->querystr("couple/name"));
			me->set("last_couple_id",me->querystr("couple/id"));
			
			targetx->set("last_couple_name",targetx->querystr("couple/name"));
			targetx->set("last_couple_id",targetx->querystr("couple/id"));
			
			me->del("couple");
			(CChar *)me->add("couple_betray",1);
			targetx->del("couple");
			(CChar *)targetx->add("couple_betray",1);
			targetx->Save();
			
			g_Channel.do_channel(me, NULL, "chat", "\n\n$HIW���»��ճ��ұ���һ�뽭�����´ߣ�\n���պ��ս���ڣ���ʤ����һ����\nԵ��Եɢ�������춨����ǿ������������\n\n");
			g_Channel.do_channel(me, NULL, "news", snprintf(msg, 255, "$HIW\n\n%s���Ậס������ʯ����ʯ��˲�伴���ڻ�Ϊһ��Һ�壬����%s�����С�\nǰ�����������̣�������������һ�ƺ���ϵ���ĺ��߽ڽڶ��䡣\n�Դ˺�%s��%s��Ϸ������֣����޹ϸ𡣡���\n\n" ,me->querystr("name"),me->querystr("name"),me->querystr("name"),targetx->querystr("name")));
		}
	}
	destruct(this);
	return 1;
}

FOOD_END;
//last, register the item into ../server/ItemSetup.cpp



