// 军团建造者
// Lanwood 2001-06-4

ITEM_BEGIN(CIbuildcorps1);

void create(int nFlag = 0)
{
    set_name("玉清符", "yu qing fu");
    set_weight(100);
    
	set("long", "传说中一代巧匠门门主公输班的令符,拥有此令就能驱使巧匠门建设帮派「宫」。");
	set("value", 400);
}

int Can_Use()
{
	return 1;
}

int do_use(CChar * me, CContainer * target)
{
	CContainer * env = me->environment();
	if(! env) return 0;

	if(env->query("city")) return notify_fail("「宫」不能建在闹市区里。");
	if(env->query("teshu")) return notify_fail("「宫」不能建在任务场景中。");
	if(env->query("sleep_room")) return notify_fail("「宫」不能建在这里！");
	if(env->Query(IS_FIGHTROOM)) return notify_fail("「宫」不能建在这里！");
	if(EQUALSTR(env->querystr("area"),"高昌"))	return notify_fail("「宫」不能建在这里！");

	if(me->querymap("corps")) return notify_fail("你必须退出帮会才能自立门户！");
	if(me->query("level") < 120) return notify_fail("以你在江湖中的地位，还不够资格建设帮会！");
	if(DIFFERSTR(me->querystr("gender"),"女性"))	return notify_fail("只有女性才可以建立「宫」！");
	if(me->query("repute") < -100000 ||me->query("repute") > 100000)
		return notify_fail("以你在江湖中的声望，还不够资格建设帮会！");
	if(me->query("威望") < 100)	return notify_fail("以你在江湖中的威望，还不够资格建设帮会！");
		
	AddMenuItem("请为你的「宫」起个名字。", "$2build $1 $2", me);
	SendMenu(me);
	return 1;
}

int build_corps(CChar * me, char * arg)
{
	CContainer * env = me->environment();
	if(! env) return 0;

	if(env->query("city")) return notify_fail("「宫」不能建在闹市区里。");
	if(env->query("sleep_room")) return notify_fail("「宫」不能建在这里！");
	
	const char * str = ccheck_legal_name(arg);
	if(str[0]) return notify_fail(str);

	if(me->query("balance") < 50000000l)
		return notify_fail("请在你的帐号里存足五千万！");

	char corps_id[20];
	char msg[255];

	sprintf(corps_id, "corp1_%s", me->id(1));
	CRoom * corps = load_room(corps_id);

	if(! corps->query("fail_ob"))		//已经有人建设过
		return notify_fail("建造失败，请重新尝试！");

	if(EQUALSTR(corps->querystr("area"),snprintf(msg, 255,"%s宫",arg)))		//已经有人建设过
		return notify_fail("建造失败，请重新尝试！！");
		
	me->add("balance", -50000000l);

	corps->del("fail_ob");
	corps->set_name(snprintf(msg, 255,"%s宫",arg), corps_id);
	corps->set("door", env->querystr("base_name"));	
	corps->set("area", snprintf(msg, 255,"%s宫",arg));
	corps->set("corps_id",corps_id);
	corps->set("level",1);
	corps->set("corp",1);
	corps->set("index",1); //帮派类型
	corps->set("corps/owner_name",me->querystr("name"));//宫主名称
	corps->set("corps/owner_id",me->querystr("id"));//宫主ID
	corps->set("corps/member_count",1);//帮派成员数目
	corps->set("corps/repute",100);//帮派初始声望
	corps->set("corps/money",2000);//帮派初始财富
	corps->set(snprintf(msg, 255,"list/%s",me->id(1)),me->name(1));
	
	corps->set("新月大殿/level",1);
	corps->set("新月大殿/sh_hp",10000+me->query_temp("max_hp")+me->query("int")*100+me->query("str")*150+me->query("dex")*50+me->query("con")*200);
	corps->set("新月大殿/sh_mp",100+me->query("max_mp")/100);
	corps->set("新月大殿/sh_level",1);
	corps->set("新月大殿/sh_index",random(17));
	corps->set("新月大殿/sh_combat_exp",1);

	//随机生成星云之魂的先天属性
	int num=random(7)+18;
	int count=84-num;
	corps->set("新月大殿/sh_str",num);
	num=random(7)+18;
	count=count-num;
	corps->set("新月大殿/sh_dex",num);
	num=random(7)+18;
	count=count-num;
	corps->set("新月大殿/sh_con",num);
	corps->set("新月大殿/sh_int",count);
	corps->set("新月大殿/sh_per",18+random(15));

	//开始计算消耗资源时间
	time_t t;	
	struct tm * newtime;
	time(&t);
	newtime = localtime(&t); 
	corps->set("day",newtime->tm_mday);
	
	corps->remove_all_doors();
	corps->setup();
	corps->Save();
	
	me->set("start_city", corps->querystr("base_name"));
	me->set("corps/id", corps_id);
	me->set("corps/level", 1);
	me->set("corps/rank", "宫主");
	me->setup();

	me->UpdateMe();
	me->Save();
	me->move(load_room(me->querystr("start_city")));

	message_vision("$HIR玉清符发出一阵耀眼的光芒，然后消失了。\n",me);
	g_Channel.do_channel(this, NULL, "news", 
		snprintf(msg, 255,"$HIW铁血江湖起硝烟，阆苑仙子下瑶池！众弟子听令，$HIR%s(%s)$HIW今日开宫立派，从今以后，天上地下，唯「$HIC%s宫$HIW」独尊！"
						,me->name(),me->id(),arg));

	destruct(this);
	return 1;
}

int handle_action(char * comm, CChar * me, char * arg)
{
	if(strcmp(comm, "build") == 0)
	{
		return build_corps(me, arg);
	}

	return CItem::handle_action(comm, me, arg);
}

char * ccheck_legal_name(const char * name)
{
   int i;
   CVector v;
   CVector valid_char;
   unsigned char ch[3];
   
   v.append("你");
   v.append("我");
   v.append("他");
   v.append("她");
   v.append("它");
   v.append("再拔剑");
   v.append("请输入姓名");

   valid_char.append("。");
   valid_char.append("‘");
   valid_char.append("’");
   valid_char.append("“");
   valid_char.append("”");
   valid_char.append("，");
   valid_char.append("、");
   valid_char.append("—");
   valid_char.append("》");
   valid_char.append("《");
   valid_char.append("（");
   valid_char.append("）");
   valid_char.append("…");
   valid_char.append("！");
   valid_char.append("？");
   valid_char.append("￥");
   valid_char.append("；");
   valid_char.append("：");
   valid_char.append("　");
      
   i = strlen(name);
   
   if( (strlen(name) < 2) || (strlen(name) > 10 ) ) 
   {
		return "对不起，名字必须是 1 到 5 个中文字。";
   }

   while(i--) 
   {
	   ch[0] = (unsigned char)name[i];
	   if( ch[0] <=' ' ) 
	   {
		   return "对不起，名字不能用控制字元。";
	   }

	   if( i%2==0 )
	   {
		   if(! ( ch[0] > 160 && ch[0] <255) ) 

	   		   return "对不起，请您用「中文」取名字。";

		   ch[1] = (unsigned char)name[i + 1];
		   if(! ( ch[1] > 160 && ch[1] <255)) 
	   		   return "对不起，请您用「中文」或「英文」取名字。";

		   ch[2] = 0;
		   if(valid_char.find((char *)ch) != valid_char.end() )
			   return "对不起，请您起个象「名字」的名字。";			
	   }
   }


   if( v.find(name) != v.end()) 
   {
		return "对不起，这种名字会造成其他人的困扰。";
   }

   return "";
}

ITEM_END;



