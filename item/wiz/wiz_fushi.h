//��ʯ
//18hell_stone.h
//2001-02-03

ITEM_BEGIN(CIwiz_fushi);

virtual void create(int nFlag = 0)		
{
	set_name("��ʯ","stone");
	
	set("value", 0l);
	
	set("no_drop", 1);
	set("no_give", 1);
	set("no_get", 1);
	
	set("owner", "lanwood");		//��¼��ʯ�����ˡ�
	
	//	set("backdoor", "����֮��");	//��¼��Ҵ��ͳ����ķ��䣬��ʼ����Ϊ����֮�š�
	
};

//��������
void init()
{
	CContainer * env = environment();
	
	if(! querystr("owner")[0] && userp(env) )
	{
		set("owner", env->querystr("id"));
		return;
	}
}

int query_autoload()
{
	return 1;
}

virtual int Can_Use()
{
	return 1;
}

virtual int do_use(CChar * me, CContainer * target)
{
	if(me->is_fighting())
		return notify_fail("������ս���У��޷�ʹ�÷�ʯ��");
	
	if(me->querymap("corps"))
		AddMenuItem("�ɳ�����", "$0trans $1 0", me); 
	
	if(me->querymap("corps"))
		AddMenuItem("�������", "$0trans $1 1", me); 
	
	if(me->querymap("corps"))
		AddMenuItem("��������", "$0task $1 2", me);
	
	SendMenu(me);
	
    return 1; 
}

virtual int handle_action(char *comm, CChar *me, char * arg)
{
	if(strcmp(comm, "trans") == 0)
		return do_go(me, atol(arg));
	
	if(me->query("grant") > CChar::GRANT_PLAYER && strcmp(comm, "goto") == 0)
		return do_goto(me, arg);
	
	if(strcmp(comm, "task") == 0)
		return do_task(me);
	
	return CItem::handle_action(comm, me, arg);
}

int do_goto(CChar * me, char * arg)
{
	char msg[255];
	
	if(! strlen(arg))
		return notify_fail("����ȥ���");
	
	CRoom * env = load_room(arg);
	
	message_vision("ֻ��$N�ó���ʯ��ĬĬ����һ�����������$P��ʧ�ڿ����С�", me);
	me->delete_temp("pending");
	me->move(env);
	tell_room(env, snprintf(msg, 255, "��â��ɢȥ��%s����Ӱ¶�˳�����", me->name()), me);
	
	return 1;
}

int do_go(CChar * me , int dest)
{
	char msg[255];
	
	const char * ro;
	
	if(me->is_fighting())
		return notify_fail("������ս����");
	
	if(dest == 0)	//������
	{
		char tmp[40];
		
		strcpy(tmp, me->environment()->querystr("base_name"));
		tmp[4] = 0;
		
		if ( DIFFERSTR(tmp, "Ұ��"))		//�ж��Ƿ��ڵ�����
			return notify_fail("�����ڲ��ڵ���֮�У���ô�ܷɳ������أ�");
		
		me->set_temp("backdoor", me->environment()->querystr("base_name"));		//��¼�ɳ�����ʱ�����ķ��䡣
		me->add("modify/power", -1);
		
		int lv = me->query("18dy/task");
		
		if ((!lv) || lv == 0 || lv != me->query("18dy/level") || lv == 1)
			ro = "����֮��1";
		
		if (lv == 2) ro = "����֮��2";
		if (lv == 3) ro = "����֮��3";
		if (lv == 4) ro = "����֮��4";
		if (lv == 5) ro = "����֮��5";
		if (lv == 6) ro = "����֮��6";
		if (lv == 7) ro = "����֮��7";
		if (lv == 8) ro = "����֮��8";
		if (lv == 9) ro = "����֮��9";
		if (lv == 10) ro = "����֮��10";
		if (lv == 11) ro = "����֮��11";
		if (lv == 12) ro = "����֮��12";
		if (lv == 13) ro = "����֮��13";
		if (lv == 14) ro = "����֮��14";
		if (lv == 15) ro = "����֮��15";
		if (lv == 16) ro = "����֮��16";
		if (lv == 17) ro = "����֮��17";
		if (lv == 18) ro = "����֮��18";
					
	}
	
	if(dest == 1)	//�����
	{	
		//�ж��Ƿ��ڵ���/
		char tmp[40];
		
		strcpy(tmp, me->environment()->querystr("base_name"));
		tmp[4] = 0;
		
		if (!DIFFERSTR(tmp, "Ұ��"))		//�ж��Ƿ��ڵ�����
			return notify_fail("���������ڵ���֮�ڣ�����Ҫ��������ˡ�");
		
		strcpy(tmp, me->querystr_temp("backdoor"));
		tmp[4] = 0;
		if ( DIFFERSTR(tmp, "Ұ��") )
			return notify_fail("ʱ�����̫�ã���ʯ�Ѳ��ǵ���ʱ��·��");			
		
		ro = me->querystr_temp("backdoor");		//���طɳ����������ĵص㡣	
	}
	
	if(me->query("mp") < 30)
		return notify_fail("��ķ������㣡");
	
	me->add("mp", -100);
	me->delete_temp("pending");
	
	message_vision("$YEL$N�ڿ��л���һ���ţ�̧�ȿ��˽�ȥ��" , me);
	
	CRoom * r = load_room(ro);
	tell_room(r, snprintf(msg, 255, "$HIB�����ֳ�һ���ţ�%s��������������", me->name()), me);
	me->move(r);	    
	
	return 1;
}

int do_task(CChar * me)
{	
	
	char msg[255];
	
	int power = me->query("modify/power");
	int boss = me->query("modify/boss");
	int num = me->query("modify/num");
	int stu = me->query("modify/study");
	
	if ((power < 1) && (boss < 1) && (num < 1) && (stu < 1))
		return notify_fail("$WHT��ʯ��Ը�����㣡$COM");
	
	message_vision(snprintf(msg, 255, "$YEL$N����һ��ɱ��%ldħ�֣�������%ld��BOSS��$COM", power, boss), me);
	message_vision(snprintf(msg, 255, "$MAG$N����һ�������%ld�����񣬻�ü���%ld�㡣$COM", num, stu), me);
	
	return 1;
}

/*
//ʹ��֮���Բ���HP��MP
int do_use(CChar * me, CContainer * target)
{
if(target && me != target) return 0;	//ֻ�ܶ��Լ�ʹ��

  int need1 = (me->query_apply("max_hp") - me->query("hp")) / 3;
  int need2 = (me->query_apply("max_mp") - me->query("mp")) / 2;
  
	if(need1 < 1) need1 = 0;
	if(need2 < 1) need2 = 0;
	
	  int point = need1 > need2 ? need1 : need2;
	  
		if(! point) return notify_fail("���������棬��ʯ�����㷢�����á�");
		
		  int provide = query("modify/power") / 30;		
		  if(! provide) return notify_fail("��Է�ʯ���������㣬�޷�ʹ�á�");
		  
			int resume = provide < point ? provide : point;
			
			  add("modify/power", - resume * 30);
			  UpdateMe();
			  
				me->receive_healing("hp", resume * 3);
				me->receive_healing("mp", resume * 2);
				
				  if(me->is_fighting())
				  {
				  CSkill::combat_magic_animate(me, me, 4);
				  me->SendMagicState();
				  me->set_use_time(3);
				  }
				  else
				  me->SendState();
				  
					return 1;
					}
*/

//�������ˣ�������ʧ
void owner_is_killed(CChar * killer)
{
	destruct(this);
}

ITEM_END;
