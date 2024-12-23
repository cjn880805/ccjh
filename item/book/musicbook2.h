//musicbook2.h
//��Ц�����������²�
//lanwood 2001-04-05

/*
ѧϰЦ���������൱֮�ѡ�
һ������ ѧϰ���ֵ�100�������ܿ�ʼ���١�
һ������ Ҫ��music ���� 100 �������� ֻ��ѧ��100��
һ������ Ҫ��music ���� 150 �������� һ������Ͳ��������١�ֻ��ѧ��100�� set("marks/xiaoao", 1);
һ����������� Ҫ�� Ц�������� ���� 100 add("marks/xiaoao", 2);  0 : �� 1: �2: �ٺ��� 3:�����
*/

ITEM_BEGIN(CImusicbook2);

void create(int nFlag = 0)
{
	set_weight(600);

	set("unit", "��");
	set("long", "����ǡ�Ц�������������ഫ��������Ϊ��Ц��������� ");
	set("value", 25000);
	set("material", "paper");

	char book_name[4][20] = {
		"����",
		"����",
		"����",
		"�������",
	};
	
	int lvl;

	if(nFlag)
		lvl = nFlag;
	else
	{
		if(! random(3))
		{
			lvl = 2;
		}
		else
		{
			lvl = 1;
		}
	
		if(! random(20))
		{
			lvl = 3;
		}
	}
	
	set("music_type", book_name[lvl]);
	set("book_type", lvl);
	set("index", lvl);
		
	char msg[80];
	set_name(snprintf(msg, 80, "��Ц����������֮%s", querystr("music_type")), "music book");

	set("no_drop", "�������������뿪�㡣");
	set("no_give", "�������������뿪�㡣");
	set("no_sell", 1);
};

int Can_Use()
{
	return 1;
}

int do_use(CChar * me, CContainer * target)
{
	say("�㷭����Ц���������������滭������Ů�ӣ����ڸ���Ū���ɫ��Ȼ��", me);
	AddMenuItem("�Ķ���Ц����������", "$9read $1", me); 
	SendMenu(me);

    return 1; 
}


virtual int handle_action(char *comm, CChar *me, char * arg)
{
	if(strcmp(comm, "read") == 0)
		return do_study(me);
	
	return 0;
}

int do_study(CChar * me)
{   
    if (me->is_busy()) 
        return notify_fail("��������æ���ء�");
               
    if( me->is_fighting() ) 
	    return notify_fail("���޷���ս����ר�������ж���֪��");
    
    if (EQUALSTR(me->querystr("gender"), "����") )
		return notify_fail("���޸����ԣ��޷�������е����");
    
    int skill = me->query_skill("music", 1);
	
	if( skill < 30)
		return notify_fail("���������о�̫ǳ���޷�������е����");

	CContainer * qin = me->query_weapon();

	if(! qin || DIFFERSTR(qin->querystr("skill_type"), "music"))
		return notify_fail("������Ұ���������ϰ��");

	int type = query("book_type");
	int music_user = me->query("marks/xiaoao");
	int myskill = me->query_skill("xiaoaojianghu", 1);

	//1, �ж��ܷ�ѧϰ
	if(type == 3)	//������
	{
		if(myskill < 100)
		{
			if(type & 1 )
				return notify_fail("��������ò��죬û�취���ٺϡ�");
			else
				return notify_fail("��������ò��죬û�취�����");
		}

		if(! (music_user & 2))
			me->set("marks/xiaoao", music_user & 2);

	}else if(type == 2)	//����
	{
		if(! myskill )	//��һ������Ӵ�ʹ�
		{
			music_user = 1;
			me->set("marks/xiaoao", 1);
		}
		else if(! (music_user & 1) )	//�����ж��Ƿ��Ѿ�����
			return notify_fail("�������Ѿ��ܴ����ˣ��ٸ������ǲ��ðɡ�");

		if(myskill > 100)
			return notify_fail("������ļ����Ѿ��൱��죬�Ȿ���׶���ûʲô���ˡ�");
	}
	else			//����
	{
		//�ж��Ƿ��Ѿ�����
		if( music_user & 1 )
			return notify_fail("���Ѿ��������ˣ���ѧ�����ǲ��ðɡ�");
		
		if(myskill > 100)
			return notify_fail("�����ٵļ����Ѿ��൱��죬�Ȿ���׶���ûʲô���ˡ�");
	}


	//2, �ж���������
	if(music_user & 1 && DIFFERSTR(qin->querystr("music_type"), "xiao"))
		return notify_fail("���������֧������ϰ��Ц������������");
	if(! (music_user & 1) && DIFFERSTR(qin->querystr("music_type"), "qin"))
		return notify_fail("��������Ұ�������ϰ��Ц������������");

	//3����ʼ��ϰ
	if(music_user & 1)	//��
	{
		if(skill < 50)
			message_vision("\n$HIY$Nת����һ֧$n$HIY��������ڴ��ߣ��а����۵Ķ��š�Ц��������������������\n", me, qin);
		else if(skill < 100)
			message_vision("\n$HIY$N��̬��Ȼ������$n$HIY��������������������ˮ��Ʈ������\n", me, qin);
		else 
			message_vision("\n$HIY$N��$n$HIY��������һ������ʱ���������������������ÿ���˵��ļ䡣\n", me, qin);
	}
	else		//��
	{
		if(skill < 50)
			message_vision("\n$MAG$N�ڳ�һ��$n$MAG��������£��а����۵Ķ��š�Ц��������������������\n", me, qin);
		else if(skill < 100)
			message_vision("\n$MAG$N�ڳ�һ��$n$MAG����ָһ������������ˮ��Ʈ������\n", me, qin);
		else 
			message_vision("\n$MAG$N��$n$MAG��������һ������ʱ���������������������ÿ���˵��ļ䡣\n", me, qin);
	}
	
	me->start_busy(5);
	me->set_temp("pending/xiaoao", 1);
	me->start_busy(do_lianxi, halt_lianxi);
	return 1;
}

static int do_lianxi(CChar * me)
{	
	int lose = me->query_skill("music");
	int skill = me->query_skill("xiaoaojianghu");

	CContainer * weapon = me->query_weapon();

	if(me->query("hp") < lose || me->query("mp") < 30 || ! weapon)
	{
		me->set_temp("pending/xiaoao", 0l);
		message_channel("study", "$HIC$N����һЦ�������ˡ�Ц������������", me);
		tell_object(me, "����������������㣬��Ҫ��Ϣһ���ˡ�", "study");
		me->SendState(me);		
		return 0;
	}
	if( skill  >= CChar::level2skill(me->query("level")) )
		return notify_fail("��ĵȼ������������ٶ�Ҳû�á�");
	//����
	if(! random(5))
	{
		if( me->query("marks/xiaoao") & 1)	//��
			message_channel("study", "$HIC$N��ɫ��Ȼ�Ĵ���$HIC$n�����������ư�Ʈ������", me, weapon);
		else
			message_channel("study", "$HIC$N��ָ��$n$HIC���ḧ����������ˮ�����ߡ���", me, weapon);
	}
	
	me->add("hp", -lose);
	me->add("mp", -30);

	me->improve_skill("xiaoaojianghu", me->query_skill("music", 1) / 3 + 1);
	return 1;
}

static int halt_lianxi(CChar * me, CChar * who, char * how)
{
	me->set_temp("pending/xiaoao", 0l);

	CContainer * weapon = me->query_weapon();
	if(! weapon) return 0;

	//��ʾ��ֹԭ����Ϣ
	if( me->query("marks/xiaoao") & 1)	//��
		message_vision("$HIYͻȻ��$n$HIY�ջ���ڣ���ɫ��Ȼ������վ��", me, weapon);
	else
		message_vision("$MAGֻ�������һ�죬$n$MAG����һ�ң�$N��̾������ָ������һ������Ѫ�ۣ�", me, weapon);
	
	me->SendState(me);
	return 1;
}


ITEM_END;
//last, register the item into ../server/ItemSetup.cpp