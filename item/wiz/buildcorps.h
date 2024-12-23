// 军团建造者
// Lanwood 2001-06-4

ITEM_BEGIN(CIbuildcorps);

void create(int nFlag = 0)
{
    set_name("建设权状", "builder");
    set_weight(100);
    
	set("long", "这是官府颁发的建筑许可。");        
}

void init()
{
	CContainer * me = environment();

	if(userp(me))
	{
		set("owner", me->id(1));		
	}
}

int Can_Use()
{
	return 1;
}

int do_use(CChar * me, CContainer * target)
{
	CContainer * env = me->environment();
	if(! env) return 0;

	if(env->query("city")) return notify_fail("总舵不能建在闹市区里。");
	if(env->query("teshu")) return notify_fail("总舵不能建在任务场景中。");
	if(env->query("sleep_room")) return notify_fail("总舵不能建在这里！");
	if(me->querymap("corps")) return notify_fail("你必须退出帮会才能自立门户！");
	if(me->query("level") < 80) return notify_fail("以你在江湖中的地位，还不够资格建设帮会！");
		
	AddMenuItem("请为你的帮会起个名字。", "$2build $1 $2", me);
	SendMenu(me);
	return 1;
}

int build_corps(CChar * me, char * arg)
{
	CContainer * env = me->environment();
	if(! env) return 0;

	if(env->query("city")) return notify_fail("总舵不能建在闹市区里。");
	if(env->query("sleep_room")) return notify_fail("总舵不能建在这里！");
	
	const char * str = ccheck_legal_name(arg);
	if(str[0]) return notify_fail(str);

	if(me->query("balance") < 10000000l)
		return notify_fail("请在你的帐号里存足一千万！");

	char corps_id[20];

	sprintf(corps_id, "corps%05ld", 1 + random(99999));
	CRoom * corps = load_room(corps_id);

	if(! corps->query("fail_ob"))		//已经有人建设过
		return notify_fail("建造失败，请重新尝试！");
		
	me->add("balance", -10000000l);

	corps->del("fail_ob");
	corps->set_name(arg, corps_id);
	corps->set("belong", env->querystr("base_name"));	

	corps->remove_all_doors();
	corps->setup();
	corps->Save();
	
	me->set("start_city", corps->querystr("base_name"));
	me->set("corps/id", corps_id);
	me->set("corps/level", 1);
	me->set("corps/rank", "主人");
	me->setup();

	me->UpdateMe();
	me->Save();

	tell_object(me, "总舵建设完毕。");
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
		   if(! ( ch[1] > 160 && ch[1] <255) ) 

	   		   return "对不起，请您用「中文」取名字。";

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



