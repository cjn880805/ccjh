CNpc * random_npc();

NPC_BEGIN(CNcorps_qingxia);

void create()
{
	set_name("��ϼ","qing xia");
    set("gender", "Ů��");
	set("icon", girl1);

    set("age", 18+random(5));
    
	set("per", 18 + random(15));
    set("combat_exp", 100);
	set("no_kill", 1);
	set("infinity", 1);		//������������
	set("is_user", 1);
	set_weight(50000000);//���ɱ�ʰȡ
	call_out(do_die, 60); //��ʱ����
	set("no_talk",1);
	set("no_huan",1);
}

int do_talk(CChar *me, char * ask)
{
	if(query(me->querystr("tradepro/quest_killnpc_id"))==99)
	{
		return CNpc::do_talk(me, ask);
	}

	if(me->querymap("corps") && ! me->is_fighting() && EQUALSTR(me->querystr("corps/id"),querystr("corps_id")))
	{
		char msg[255];
		AddMenuItem(snprintf(msg, 255,"��%s��ȡ��������",name()), "$0get_renwu $1", me);
		AddMenuItem(snprintf(msg, 255,"��%sѯ������",name()), "$0ask_renwu $1", me);
		AddMenuItem(snprintf(msg, 255,"��%sҪ���������",name()), "$0cancel_renwu $1", me);
		AddMenuItem(snprintf(msg, 255,"��%s��ȡ���̽�����������",name()), "$0get_huan $1", me);
		if(me->querymap("tradepro"))
		{
			AddMenuItem("��ѯĿǰ�ġ��̽�����������˵��", "$0show_huan $1", me);
			if(query("ȡ��"))
				AddMenuItem("�����̽�����������ʧ��", "$0cancel_huan $1", me);
		}
		SendMenu(me);
	}
	return 1;
}

int handle_action(char *comm, CChar *me, char *arg)
{
	if(me->querymap("corps") && EQUALSTR(me->querystr("corps/id"),querystr("corps_id")))
	{
		if(strcmp(comm, "ask_renwu") == 0)
			return do_aq(me);
		if(strcmp(comm, "get_renwu") == 0)
			return do_gq(me);
		if(strcmp(comm, "cancel_renwu") == 0)
			return do_cancel(me);
		if(strcmp(comm, "get_huan") == 0 )
			return do_huan(me);
		if(strcmp(comm, "show_huan") == 0 && me->querymap("tradepro") )
			return do_show(me);
		if(strcmp(comm, "cancel_huan") == 0 && me->querymap("tradepro") )
			return do_cancel_huan(me);
		
	}
	return CNpc::handle_action(comm, me, arg);
}

virtual void init(CChar * me)
{	
	CNpc::init(me);

	if( ! is_fighting() ) 
	{
		if(query(me->id(1)) ==1 )
			set(me->id(1),99);
	}
}

//��������
int do_aq(CChar * me)
{
	if(!me->query_temp("corps/money/overtime"))
	{
	    message_vision("$n����$N������üë��΢΢һЦ��", me,this);
		say("����Դ���������ȡ�����Ի�þ���Ľ�����", me);
		say("��ɵ�����Խ�࣬�����Խ�ߡ�", me);
		say("��Ȼ�����Ҫ�������û��ɣ���Ҫ�ܳͷ��ġ�", me);
		SendMenu(me);
		return 1;
	}
	long i;
	long e;
	
	char msg[255];

	i=current_time;
	e=me->query_temp("corps/money/overtime");
	if (i>e)
	{
	    message_vision("$N������üͷ��",this);
		say("�Բ��𡭡�ʱ���Ѿ����ˣ���û���������", me);
		SendMenu(me);
		return 1;
	}
	i=e-i;
	e=i/60;
	i=i-e*60;

    say(snprintf(msg, 255,"%s΢΢��ü�������������롭��",name()),me);
	say(snprintf(msg, 255, "%s˵�������������ڵ�������Ѱ��%s��", name(),me->querystr_temp("corps/money/name")), me);
	say(snprintf(msg, 255, "%s˵������������ʱ�޻���%d��%d�롭��", name(),e,i), me);
	SendMenu(me);
	return 1;
}

int do_show(CChar * me)
{
	char msg[255];
	if(!me->query_temp("tradepro/money"))
	{
		say("�����2001��Ǯ���ҾͰ����������ڵ�������ʲô��", me);
		SendMenu(me);
		return 1;
	}
	me->delete_temp("tradepro/money");
	
	if(current_time > me->query("tradepro/quest_time"))
	{
		say("������̫���ˣ���������Ѿ������ˡ�",me);
		SendMenu(me);
		me->del("tradepro");
		return 1;
	}
	switch(me->query("tradepro/index"))
	{
	case 1:
		snprintf(msg, 255,"�����ڵ����񣨵�%d�����ǣ����� %s ȥ�� %s��ʣ��ʱ���ǣ� %d �롣",
			me->query("tradepro/quest_count"),me->querystr("tradepro/quest_npc_name"),
			me->querystr("tradepro/quest_item_name"),me->query("tradepro/quest_time")-current_time);
		break;
	case 2:
		snprintf(msg, 255,"�����ڵ����񣨵�%d�����ǣ����� %s ȥ�� %s��ʣ��ʱ���ǣ� %d �롣",
			me->query("tradepro/quest_count"),me->querystr("tradepro/quest_npc_name"),
			me->querystr("tradepro/quest_killnpc_name"),me->query("tradepro/quest_time")-current_time);
		break;
	case 3:
		snprintf(msg, 255,"�����ڵ����񣨵�%d�����ǣ����� %s ɱ�� %s��ʣ��ʱ���ǣ� %d �롣",
			me->query("tradepro/quest_count"),me->querystr("tradepro/quest_npc_name"),
			me->querystr("tradepro/quest_killnpc_name"),me->query("tradepro/quest_time")-current_time);
		break;
	case 4:
		snprintf(msg, 255,"�����ڵ����񣨵�%d�����ǣ����� %s ץ�� %s��ʣ��ʱ���ǣ� %d �롣",
			me->query("tradepro/quest_count"),me->querystr("tradepro/quest_npc_name"),
			me->querystr("tradepro/quest_killnpc_name"),me->query("tradepro/quest_time")-current_time);
		break;
	case 5:
		snprintf(msg, 255,"�����ڵ����񣨵�%d�����ǣ����� %s �� %s �ش�Ѳ�ߣ�ʣ��ʱ���ǣ� %d �롣",
			me->query("tradepro/quest_count"),me->querystr("tradepro/quest_npc_name"),
			me->querystr("tradepro/quest_killnpc_mp"),me->query("tradepro/quest_time")-current_time);
		break;
	case 6:
		snprintf(msg, 255,"�����ڵ����񣨵�%d�����ǣ����� %s ǰ�� %s �ֻع�����ɱ�����Ŵ���ӣ���ʣ��ʱ���ǣ� %d �롣",
			me->query("tradepro/quest_count"),me->querystr("tradepro/quest_npc_name"),
			me->querystr("tradepro/quest_killnpc_mp"),me->query("tradepro/quest_time")-current_time);
		break;
	case 7:
		snprintf(msg, 255,"�����ڵ����񣨵�%d�����ǣ��ҵ�������Ա%s(%s)����������������һ�£�ʣ��ʱ���ǣ� %d �롣",
			me->query("tradepro/quest_count"),me->querystr("tradepro/quest_killnpc_name"),
			me->querystr("tradepro/quest_killnpc_id"),me->query("tradepro/quest_time")-current_time);
		break;
	case 8:
		if(me->query("tradepro/quest_pro_index")==1)
		{
			snprintf(msg, 255,"�����ڵ����񣨵�%d�����ǣ�Ϊ������������ %s ����ŵ���������ܾ��鵽 %d��ʣ��ʱ���ǣ� %d �롣",
				me->query("tradepro/quest_count"),me->querystr("tradepro/quest_npc_name"),
				me->query("tradepro/quest_pro_point"),me->query("tradepro/quest_time")-current_time);
		}
		else
		{
			snprintf(msg, 255,"�����ڵ����񣨵�%d�����ǣ�Ϊ������������ %s ����ŵ�������������� %d��ʣ��ʱ���ǣ� %d �롣",
				me->query("tradepro/quest_count"),me->querystr("tradepro/quest_npc_name"),
				me->query("tradepro/quest_pro_point"),me->query("tradepro/quest_time")-current_time);
		}
		break;
	case 9:
		snprintf(msg, 255,"�����ڵ����񣨵�%d�����ǣ���Ӧ %s ȥ��һ���ڣ�ʣ��ʱ���ǣ� %d �롣",
			me->query("tradepro/quest_count"),me->querystr("tradepro/quest_npc_name"),
			me->query("tradepro/quest_time")-current_time);
		break;
	case 10:
		if(me->query("tradepro/quest_killnpc_time")-current_time>0)
		{
			snprintf(msg, 255,"�����ڵ����񣨵�%d�����ǣ����� %s ���� %s ��ȷ������ʣ��ʱ��� %d ���в�����",
				me->query("tradepro/quest_count"),me->querystr("tradepro/quest_npc_name"),
				me->querystr("tradepro/quest_killnpc_name"),me->query("tradepro/quest_killnpc_time")-current_time);
		}
		else
		{
			snprintf(msg, 255,"�����ڵ����񣨵�%d�����ǣ����� %s ���� %s ���������Ѿ����������",
				me->query("tradepro/quest_count"),me->querystr("tradepro/quest_npc_name"),
				me->querystr("tradepro/quest_killnpc_name"));
		}
		break;
	case 11:
		snprintf(msg, 255,"�����ڵ����񣨵�%d�����ǣ��� %s �Ϲ� %d �����ӣ�ʣ��ʱ���ǣ� %d �롣",
			me->query("tradepro/quest_count"),me->querystr("tradepro/quest_npc_name"),
			me->query("tradepro/quest_item_numer"),me->query("tradepro/quest_time")-current_time);
		break;
	case 12:
		snprintf(msg, 255,"�����ڵ����񣨵�%d�����ǣ��� %s ��ȥ %s��ʣ��ʱ���ǣ� %d �롣",
			me->query("tradepro/quest_count"),me->querystr("tradepro/quest_npc_name"),
			me->querystr("tradepro/quest_item_name"),me->query("tradepro/quest_time")-current_time);
		break;
	case 13:
		snprintf(msg, 255,"�����ڵ����񣨵�%d�����ǣ����� %s �ռ� %s %d�ݣ�ʣ��ʱ���ǣ� %d �롣",
			me->query("tradepro/quest_count"),me->querystr("tradepro/quest_npc_name"),
			me->querystr("tradepro/quest_item_name"),me->query("tradepro/quest_item_numer"),me->query("tradepro/quest_time")-current_time);
		break;
	case 14:
			snprintf(msg, 255,"�����ڵ����񣨵�%d�����ǣ����� %s ��� %s �Ļ���ʣ��ʱ���ǣ� %d �롣",
			me->query("tradepro/quest_count"),me->querystr("tradepro/quest_npc_name"),
			me->querystr("tradepro/quest_killnpc_name"),me->query("tradepro/quest_time")-current_time);
		break;
	}
	say(msg, me);
	SendMenu(me);
	return 1;
}

int do_cancel_huan(CChar * me)
{
	if(!me->querymap("tradepro"))
	{
		say("�㲢û����ȡ���񡭡�", me);
		SendMenu(me);
		return 1;
	}
	say("�Ҷ��������̫ʧ���ˡ���",me);
	SendMenu(me);
	me->del("tradepro");
	return 1;
}

int do_cancel(CChar * me)
{
	if(!me->query_temp("corps/money/overtime"))
	{
		say("�㲢û����ȡ���񡭡�", me);
		SendMenu(me);
		return 1;
	}
	say("�����1001��Ǯ���Ҿ������ε�����", me);
	SendMenu(me);
	return 1;
}

const char * position_npc(CChar * npc)
{
	CContainer * env = npc->environment();
	if(! env) return 0;	//ʧ��
	if(env->query("no_fight")) return 0;	//��ս������
	if(EQUALSTR(env->querystr("area"), "house")) return 0;	//���סլ

	while(env->environment())
		env = env->environment();

	return env->name(1);
}

int do_huan(CChar * me)
{
	if(me->query("trade/score")< 50000)
		return notify_fail("�ܱ�Ǹ���������ֻ������������������ġ��춥���ˡ��ſ���ȥ����");

	if(me->query("level")<60)
		return notify_fail("Ϊ����İ�ȫ���������������ǿ��Ϊ��60�����������Ұɣ�");
	
	if(me->query("balance") < 100000)
		return notify_fail("��������ʺ������ʮ��");

	char msg[255];
	CContainer * env = load_room(querystr("corps_id"));
	if(env->query(snprintf(msg, 255,"repute/%s",me->id(1)))<10000)
		return notify_fail("���뱾����������ı��ֻ��ǲ������⣬����������߱����������������ɣ�");

	if(env->query(snprintf(msg, 255,"money/%s",me->id(1)))<10000)
		return notify_fail("���뱾����������ı��ֻ��ǲ������⣬����������߱����ĲƸ��������ɣ���");

	if(me->querymap("tradepro") )
		return notify_fail("�㲻���Ѿ��ӹ���������");

	static char index2[5][255] =
	{
		"�þò���$HIW%s$COM�ˣ��鷳��ȥ�ҵ���˵����������",
			"$HIW%s$COMǰ��ʱ�����������ݷã���һֱ��ûʱ��ط�,����������ȥ��������",
			"$HIW%s$COM�Ѿ�ʧ�ٺܾ���,���Ƿ��п�����ȥ�������������������ô���ˣ�",
			"�Һ�����$HIW%s$COM�����ܲ��������͸����Ÿ������������ʺ�����",
			"ǰ��ʱ���Ҵ�Ӧ$HIW%s$COMȥ��ɽ��ˮ�ģ���һֱæ���������˵��������пգ�����һ������С�",
	};

	me->add("balance",-100000);

	CNpc * npc;

	int i;
	const char * area;
	for(i=0;i<10000;i++)
	{
		npc = random_npc();
		
		if(! npc ) continue;
		if(! living(npc)) continue;	//���NPC�첻���ˡ�
		if(DIFFERSTR(npc->querystr("race"), "����") ) continue;	//������NPC
		if(npc->query("no_kill")) continue;	//��һ����Ҳ������ҵ����������
		if(npc->query("mfnpc_lvl")) continue;	//������ɽ���������
		if(npc->query("no_talk")) continue;	//���NPC����������
		
		env = npc->environment();
		
		//�����ж�NPC���µķ�λ
		area = position_npc(npc);
		if(! area ) continue;	//���NPCû�л���
		if(! area[0]) continue;	//���NPC����ҷ������ս���С�
		if(EQUALSTR(env->querystr("area"), "fight") ) continue;	//���NPC����ҷ������ս���С�
		if(EQUALSTR(env->querystr("area"), "Ұ��") ) continue;	//���NPC��Ұ�⡣
		if(env->query("renwu") ) continue;	//���NPC����������ķ����С�
		break;
	}

	double value = 1800;		//30����
	time_t t;
	time(&t);
	t += (time_t)value;	

	me->set("tradepro/quest_time",t+i);

	me->set("tradepro/index",2);
	me->set("tradepro/quest_npc_id",npc->querystr("id"));
	me->set("tradepro/quest_npc_name",npc->querystr("name"));
	tell_object(me, snprintf(msg, 255, index2[random(5)], me->querystr("tradepro/quest_npc_name")));

	return 1;
}

virtual int accept_object(CChar * who, CContainer * ob)
{
	if(who->querymap("corps") && EQUALSTR(who->querystr("corps/id"),querystr("corps_id")))
	{
		long i,money;
		char msg[255];
		
		if (EQUALSTR(ob->querystr("id"), "coin") && ob->query("value")==1001)
		{
			who->delete_temp("corps/money");
			destruct(ob);
			return 1;
		}

		if (EQUALSTR(ob->querystr("id"), "coin") && ob->query("value")==2001 && who->querymap("tradepro") )
		{
			who->set_temp("tradepro/money",1);
			destruct(ob);
			return 1;
		}
		
		if ( DIFFERSTR(ob->querystr("id"), who->querystr_temp("corps/money/id")) || DIFFERSTR(ob->querystr("name"), who->querystr_temp("corps/money/name")) )
		{	
			say(snprintf(msg, 255,"%s����üë��˵������ʲô������", name()),who);
			SendMenu(who);
			return 0;
		}
		
		if( ob->query("is_user") )
		{
			say(snprintf(msg, 255,"%sҡҡͷ������ʲô�������Ҳ�Ҫ��", name()), who);
			SendMenu(who);
			return 0;
		}
		
		long e;
		
		e=who->query_temp("corps/money/overtime");
		i=current_time;
		
		if (i>e)
		{
			destruct(ob);	
			say(snprintf(msg, 255,"%sһ��üë��˵����֪��ʱ���Ѿ�������", name()), who);
			SendMenu(who);
			return 1;
		}
		
		who->add_temp("corps/money/finish",1);
		i=who->query_temp("corps/money/exp");
		e=who->query_temp("corps/money/finish");
		money=e;
		if(money>150)
			money=100+random(50);
		if(e<30)
			i=i*(e+5)/5;
		else
			i=i*6;
		i=(random(i)+i)*6/3;
		i=i+(100-who->query("level"))/3;
		
		who->add("combat_exp",i);
		int repute=1;
		if(who->query("repute")<0)
			repute=-repute;
		who->add("repute",repute);
		who->delete_temp("corps/money/id");
		who->delete_temp("corps/money/name");
		who->delete_temp("corps/money/exp");
		who->delete_temp("corps/money/overtime");
		
		CContainer * env = load_room(querystr("corps_id"));
		env->add(snprintf(msg, 255,"money/%s",who->id(1)),money);
		env->add("corps/money",money);
		
		message_vision("$n��$N������üë��¶��һ˿Ц�ݡ�", who,this);
		tell_object(who,snprintf(msg, 255, "������%d���顢%d��Ľ���������%d��İ��ɲƸ���", i,repute,money));
		
		destruct(ob);
	}

	return 1;
}

int do_gq(CChar * me)
{
	long i;
	long e;
	char msg[255];
	
	static char weapon_name[62][40] = {
		"blade_1","blade_2","cleansword","dadao","zimuzhen",
			"dadao2","dafu","dagger","duanjian","fenshuici","fork","fuchen","futou",
			"hammer","heilongbian",	"hothammer","huaji","huoqiang","jinhua","jinlun",
			"jiujiebian","kandao","kuihuazhen","leizhendang","mandao","panguanbi",
			"putongbishou","qimeigun","qin","qingzugang","qingzuzang","qinqin_sword","ruanjian",
			"senggun","shebian","shenghuo_ling","shezhang","shield","shunvjian","shutonggun","snowsword","sword_1",
			"sword_2","sword_3","tiepipa","tongren","walkingstick","wandao","wodao","xblade",
			"xiao","xiuhua","xuantiesword","xuedao","yangbian","yaochu","yaoqin","yinlun",
			"yufeng_zhen","yuxiao","yuzhu_zhang","zijin_staff",
	};
	
	static char cloth_name[139][40]={
		"cloth","pixue","dao_xie","daopaocyan_cloth","female1_cloth","female2_cloth","female3_cloth",
			"female6_cloth","flower_shoe","green_cloth","greenrobe","greyrobe","gunny_shoes","hui_cloth",
			"huwan","huyao","jin","jindai","jinduan","junfu","male1_cloth",
			"male3_cloth","male4_cloth","male6_cloth","male7_cloth","male8_cloth","male_shoe","necklace",
			"ni_cloth","ni_xie","pink_cloth","piqiu","qing_cloth","qingyi","r_jiasha","ring",
			"seng_cloth","seng_xie","sengmao","sengxie","shepi","shoe","shoutao","shuikao","shouzhuo","tiejia",
			"surcoat","test","toukui","white_robe","wuxingfu","xu_cloth","xuan_cloth","y_jiasha","yaodai",
			"yayi_cloth","ycloth","yupei","zhanyi","zhenzhu","tiezhitao","zichoushan","b_jiasha","baguafu",
			"baichou","baipao","bduanqun","beixin","belt","blackcloth","bluecloth","boots","bu_shoes",
			"bupao","c_jiasha","caoxie","changpao","changpao2","cheng_cloth","choupao","cloth2","connie",
			"cuiyu","cycle","cynrobe","dao_cloth","doupeng","dress","feather","fu_cloth",
			"goldring","goupi","guazi","gui_dress","hat","hupi","hushenfu","jade_belt","jinsijia","jjunfu","kenao","lace",
			"linen","liu_dress","magcloth","magua","marry_dress","mini_dress","moon_dress","pink_dress",
			"qi_dress","qun","red_dress","ruanwei","scarf","sha_dress","shoes","shoupa","skirt",
			"shudai","tduanqun","tiebeixin","tiehuwan","tiehuyao","tieshou","tongqun","ttoujin","wchangqun","wcloth","wdahui",
			"whitecloth","whitecloth1","xian_cloth","xiaoao","xiu_cloth","xiu_scarf","yan_dress","zi_dress","mask",
	};
	
	static char food_name[48][40]={
		"baihe","baozi","duanchang","gourou","guijia","guiyuan","heiyugao","honghua",
			"jinchuang","jitui","jiudai","jindan","kaoya","marz","menghan_yao","mizhitianou","moyao",
			"nverhong","peanut","putizi","qingdan","qingke_m","renshen",
			"shedan","shedangao","sherou","turou","x_drug","xiaohuan_dan","xionghuang",
			"yadan","yangxin","yuchandan","zongzi","zhutou","zhujingchan","yangjing","xiang","gao","egg","dahuan_dan",
			"cha","caomei","cake","luobo","caogeng","jingxin_san","honey",
	};
	
	i=current_time;

	e=me->query_temp("corps/money/overtime");
	if(e && i>e)
	{
	    message_vision("$N������ü��",this);
		say("����һ������û����ɡ���", me);
		SendMenu(me);
		me->delete_temp("corps/money");	
	
		me->set("hp",me->query("hp")/2);
		me->set("mp",me->query("mp")/2);
	}

	if(e && i<=e)
	{
	    message_vision("$N������ü��",this);
		say("����һ������û��ɡ���", me);
		SendMenu(me);
		return 1;
	}

	i=me->query("level");
	e=i/3;
	i=i-e+2*random(e);
	const char * shuiname = "";
	const char * shuiid = "";
	int shuitime = 0;
	int shuiexp = 0;

	int task = random(3);

	CContainer * item_name;
	switch(task)
	{
	case 0:
		item_name=load_item(cloth_name[random(139)]);
		break;
	case 1:
		item_name=load_item(food_name[random(48)]);
		break;
	case 2:
		item_name=load_item(weapon_name[random(62)]);
		break;
	}
	
	shuiname=item_name->name();
	shuiid=item_name->id();
	shuitime=60;
	switch(i/10)
	{
	case 0:
		shuiexp=random(3)+2;
		break;
	case 1:
		shuiexp=random(6)+5;
		break;
	case 2:
		shuiexp=random(8)+10;
		break;
	case 3:
		shuiexp=random(11)+20;
		break;
	case 4:
		shuiexp=random(18)+30;
		break;
	case 5:
		shuiexp=random(22)+50;
		break;
	case 6:
		shuiexp=random(30)+50;
		break;
	case 7:
		shuiexp=random(14)+60;
		break;
	case 8:
		shuiexp=random(40)+60;
		break;
	default:
		shuiexp=random(20)+80;
	}
	
	me->set_temp("corps/money/name",shuiname);
	me->set_temp("corps/money/id",shuiid);
	me->set_temp("corps/money/exp",shuiexp);

	say(snprintf(msg, 255, "%s˵����ȥ��%s���ҡ���", name(),shuiname), me);
	i=400-me->query("level");
	i=i+shuitime;
	i=(i+random(i))/2;
	me->set_temp("corps/money/overtime",current_time+i);
	e=i/60;
	i=i-e*60;
	say(snprintf(msg, 255, "%s˵��������%d��%d��ȥ��ɰɡ�", name(),e,i), me);
	SendMenu(me);

	return 1;
}

static void do_die(CContainer * ob, LONG param1, LONG param2)
{
	CChar * me = (CChar *)ob;
	if(me->query("pq"))
	{
		if(me->query("leave_time"))
		{
			me->add("leave_time",-1);
			me->call_out(do_die1, 3600);
		}
		else
			me->call_out(do_die1, 60);
	}
}

static void do_die1(CContainer * ob, LONG param1, LONG param2)
{
	CChar * me = (CChar *)ob;
	if(me->query("leave_time") <= 0)
	{
		char msg[255];
		tell_room(me->environment(), snprintf(msg, 255, "$HIR%sƮȻ��ȥ��",me->name()));
		destruct(me);
		return;
	}
	me->add("leave_time", -1);
	me->call_out(do_die1, 3600);
}


NPC_END;



